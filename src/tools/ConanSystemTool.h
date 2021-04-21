/**
 * @copyright Copyright (c) 2019 B-com http://www.b-com.com/
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author Loïc Touraine
 *
 * @file
 * @brief description of file
 * @date 2019-11-15
 */

#ifndef CONANSYSTEMTOOL_H
#define CONANSYSTEMTOOL_H

#include "SystemTools.h"

class ConanSystemTool : public BaseSystemTool
{
public:
    typedef enum {
        cmake = 0x01,
        cmake_multi = 0x02,
        cmake_paths = 0x04,
        cmake_find_package = 0x08,
        cmake_find_package_multi = 0x0F,
        compiler_args = 0x10,
        qmake = 0x20,
        pkg_config = 0x40,
        txt = 0x80,
        json = 0xF0,
        make = 0x100,
        markdown = 0x200,
        deploy = 0x400
    } GeneratorType;
    ConanSystemTool(const CmdOptions & options):BaseSystemTool(options, "conan") {}
    ~ConanSystemTool() override = default;
    void update() override;
    void bundle(const Dependency & dependency) override;
    void install(const Dependency & dependency) override;
    bool installed(const Dependency & dependency) override;
    std::vector<std::string> binPaths(const Dependency & dependency) override;
    std::vector<std::string> libPaths(const Dependency & dependency) override;
    std::string computeSourcePath( const Dependency &  dependency) override;
    void invokeGenerator(const fs::path & conanFilePath, GeneratorType generator);


private:
    std::string computeToolRef( const Dependency &  dependency) override;
};

#endif