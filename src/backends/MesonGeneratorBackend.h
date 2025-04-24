/**
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
 * @date 2024-11-21
 */

#ifndef MESONGENERATORBACKEND_H
#define MESONGENERATORBACKEND_H
#include "backends/IGeneratorBackend.h"

class MesonGeneratorBackend : virtual public AbstractGeneratorBackend
{
public:
    MesonGeneratorBackend(const CmdOptions & options):AbstractGeneratorBackend(options,".options") {}
    ~MesonGeneratorBackend() override = default;
    std::pair<std::string, fs::path> generate(const std::vector<Dependency> & deps, Dependency::Type depType) override;
    void generateIndex(std::map<std::string,fs::path> setupInfos) override;
    void generateConfigureConditionsFile(const fs::path &  rootFolderPath, const std::vector<Dependency> & deps) override;
    void parseConditionsFile(const fs::path &  rootFolderPath, std::map<std::string,bool> & conditionsMap) override;
};

#endif // MESONGENERATORBACKEND_H
