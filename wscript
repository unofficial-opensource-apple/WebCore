#! /usr/bin/env python

# Copyright (C) 2009 Kevin Ollivier  All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY APPLE COMPUTER, INC. ``AS IS'' AND ANY
# EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL APPLE COMPUTER, INC. OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
# OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
# OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. 
#
# WebCore build script for the waf build system

from settings import *

webcore_sources = {}

if build_port == "wx":
    if building_on_win32:
        webcore_dirs.extend(['platform/wx/wxcode/win', 'plugins/win'])
        webcore_sources['wx-win'] = [
               # wxTimer on Windows has a bug that causes it to eat crashes in callbacks
               # so we need to use the Win port's implementation until the wx bug fix is
               # widely available (it was fixed in 2.8.10).
               'platform/graphics/win/TransformationMatrixWin.cpp',
               'platform/win/SharedTimerWin.cpp',
               # Use the Windows plugin architecture
               'page/win/PageWin.cpp',
               'plugins/win/PluginDataWin.cpp',
               'plugins/win/PluginDatabaseWin.cpp',
               'plugins/win/PluginMessageThrottlerWin.cpp',
               'plugins/win/PluginPackageWin.cpp',
               'plugins/win/PluginViewWin.cpp',
        ]
    elif sys.platform.startswith('darwin'):
        webcore_dirs.append('plugins/mac')
        webcore_dirs.append('platform/wx/wxcode/mac/carbon')
        webcore_dirs.append('platform/mac')
        webcore_sources['wx-mac'] = [
               'platform/mac/WebCoreNSStringExtras.mm',
               'platform/mac/PurgeableBufferMac.cpp',
               'plugins/wx/PluginDataWx.cpp',
               'plugins/mac/PluginPackageMac.cpp',
               'plugins/mac/PluginViewMac.cpp'
        ]
    else:
        webcore_sources['wx-gtk'] = [
               'plugins/PluginDataNone.cpp',
               'plugins/PluginViewNone.cpp',
               'plugins/PluginPackageNone.cpp'
        ]
        webcore_dirs.append('platform/wx/wxcode/gtk')
        
import TaskGen
from TaskGen import taskgen, feature, after
import Task, ccroot

def generate_webcore_derived_sources():
    # build the derived sources
    derived_sources_dir = os.path.join(webcore_dir, 'DerivedSources')
    wc_dir = webcore_dir
    if building_on_win32:
        wc_dir = get_output('cygpath --unix "%s"' % wc_dir)
    if not os.path.exists(derived_sources_dir):
        os.mkdir(derived_sources_dir)

    olddir = os.getcwd()
    os.chdir(derived_sources_dir)

    os.system('make -f %s/DerivedSources.make WebCore=%s SOURCE_ROOT=%s all FEATURE_DEFINES="%s"' % (wc_dir, wc_dir, wc_dir, ' '.join(feature_defines)))
    os.chdir(olddir)

def set_options(opt):
    common_set_options(opt)

def configure(conf):
    common_configure(conf)
    generate_webcore_derived_sources()

def build(bld):
    import Options
    if sys.platform.startswith('darwin'):
        TaskGen.task_gen.mappings['.mm'] = TaskGen.task_gen.mappings['.cxx']
    
    wk_includes = ['.', '..', 'DerivedSources',
                wk_root, 
                os.path.join(wk_root, 'JavaScriptCore'),
                os.path.join(wk_root, 'WebCore'),
                'platform/image-decoders',
                'platform/wx/wxcode',
                'workers',
        ]

    features = [build_port]
    exclude_patterns = ['*None.cpp', '*CFNet.cpp', '*Qt.cpp', '*Win.cpp', '*Wince.cpp', '*Gtk.cpp', '*Mac.cpp', '*Safari.cpp', '*Chromium*.cpp','*SVG*.cpp', '*AllInOne.cpp', 'test*bindings.*']
    if build_port == 'wx':
        features.append('curl')
        
    if sys.platform.startswith('darwin'):
        features.append('cf')
    else:
        exclude_patterns.append('*CF.cpp')

    full_dirs = get_dirs_for_features(webcore_dir, features=features, dirs=webcore_dirs)

    jscore_dir = os.path.join(wk_root, 'JavaScriptCore')
    for item in os.listdir(jscore_dir):
        fullpath = os.path.join(jscore_dir, item)
        if os.path.isdir(fullpath) and not item == "os-win32" and not item == 'icu':
            wk_includes.append(fullpath)

    wk_includes.append(os.path.join(jscore_dir, 'wtf', 'unicode'))
    wk_includes.append(os.path.join(jscore_dir, 'wtf', 'unicode', 'icu'))
    wk_includes += common_includes + full_dirs

    cxxflags = []
    if building_on_win32:
        cxxflags.append('/FIWebCorePrefix.h')
    else:
        cxxflags.extend(['-include', 'WebCorePrefix.h'])

    webcore = bld.new_task_gen(
        features = 'cc cxx cstaticlib',
        includes = ' '.join(wk_includes),
        source = ' '.join(flattenSources(webcore_sources.values())),
        cxxflags = cxxflags,
        target = 'webcore',
        uselib = 'WX ICU XML XSLT CURL SQLITE3 ' + get_config(),
        uselib_local = '',
        install_path = output_dir,
        )
        
    excludes = []
    
    if build_port == 'wx':
        excludes = get_excludes(webcore_dir, exclude_patterns)
        excludes.extend(['UserStyleSheetLoader.cpp', 'RenderMediaControls.cpp'])


        # FIXME: undo this once these classes are fully implemented
        excludes.append('SocketStreamErrorBase.cpp')
        excludes.append('SocketStreamHandleBase.cpp')

        # intermediate sources
        excludes.append('CSSValueKeywords.c')
        excludes.append('CSSPropertyNames.cpp')
        excludes.append('tokenizer.cpp')

        # FIXME: these three require headers that I can't seem to find in trunk.
        # Investigate how to resolve these issues.
        excludes.append('JSAbstractView.cpp')
        excludes.append('JSPositionCallback.cpp')
        excludes.append('JSDOMStringList.cpp')
        excludes.append('JSInspectorController.cpp')
        if building_on_win32:
            excludes.append('SharedTimerWx.cpp')
            
        excludes.append('AuthenticationCF.cpp')
        excludes.append('LoaderRunLoopCF.cpp')
        
    webcore.find_sources_in_dirs(full_dirs, excludes = excludes, exts=['.c', '.cpp'])
