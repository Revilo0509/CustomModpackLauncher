// SPDX-FileCopyrightText: 2023 flowln <flowlnlnln@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only AND Apache-2.0
/*
 *  Prism Launcher - Minecraft Launcher
 *  Copyright (C) 2022 Sefa Eyeoglu <contact@scrumplex.net>
 *  Copyright (c) 2023 Trial97 <alexandru.tripon97@gmail.com>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, version 3.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * This file incorporates work covered by the following copyright and
 * permission notice:
 *
 *      Copyright 2013-2021 MultiMC Contributors
 *
 *      Licensed under the Apache License, Version 2.0 (the "License");
 *      you may not use this file except in compliance with the License.
 *      You may obtain a copy of the License at
 *
 *          http://www.apache.org/licenses/LICENSE-2.0
 *
 *      Unless required by applicable law or agreed to in writing, software
 *      distributed under the License is distributed on an "AS IS" BASIS,
 *      WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *      See the License for the specific language governing permissions and
 *      limitations under the License.
 */

#pragma once

#include "modplatform/ResourceAPI.h"

#include "ui/pages/modplatform/DataPackPage.h"
#include "ui/pages/modplatform/ModPage.h"
#include "ui/pages/modplatform/ResourcePackPage.h"
#include "ui/pages/modplatform/ShaderPackPage.h"
#include "ui/pages/modplatform/TexturePackPage.h"

namespace ResourceDownload {

namespace TeamCivitas {
static inline QString displayName()
{
    return "TeamCivitas";
}
static inline QIcon icon()
{
    return QIcon::fromTheme("TeamCivitas");
}
static inline QString id()
{
    return "TeamCivitas";
}
static inline QString debugName()
{
    return "TeamCivitas";
}
static inline QString metaEntryBase()
{
    return "TeamCivitasPacks";
}
}  // namespace TeamCivitas

class TeamCivitasModPage : public ModPage {
    Q_OBJECT

   public:
    static TeamCivitasModPage* create(ModDownloadDialog* dialog, BaseInstance& instance)
    {
        return ModPage::create<TeamCivitasModPage>(dialog, instance);
    }

    TeamCivitasModPage(ModDownloadDialog* dialog, BaseInstance& instance);
    ~TeamCivitasModPage() override = default;

    bool shouldDisplay() const override;

    inline auto displayName() const -> QString override { return TeamCivitas::displayName(); }
    inline auto icon() const -> QIcon override { return TeamCivitas::icon(); }
    inline auto id() const -> QString override { return TeamCivitas::id(); }
    inline auto debugName() const -> QString override { return TeamCivitas::debugName(); }
    inline auto metaEntryBase() const -> QString override { return TeamCivitas::metaEntryBase(); }

    inline auto helpPage() const -> QString override { return "Mod-platform"; }

    std::unique_ptr<ModFilterWidget> createFilterWidget() override;

   protected:
    virtual void prepareProviderCategories() override;
    Task::Ptr m_categoriesTask;
};

class TeamCivitasResourcePackPage : public ResourcePackResourcePage {
    Q_OBJECT

   public:
    static TeamCivitasResourcePackPage* create(ResourcePackDownloadDialog* dialog, BaseInstance& instance)
    {
        return ResourcePackResourcePage::create<TeamCivitasResourcePackPage>(dialog, instance);
    }

    TeamCivitasResourcePackPage(ResourcePackDownloadDialog* dialog, BaseInstance& instance);
    ~TeamCivitasResourcePackPage() override = default;

    bool shouldDisplay() const override;

    inline auto displayName() const -> QString override { return TeamCivitas::displayName(); }
    inline auto icon() const -> QIcon override { return TeamCivitas::icon(); }
    inline auto id() const -> QString override { return TeamCivitas::id(); }
    inline auto debugName() const -> QString override { return TeamCivitas::debugName(); }
    inline auto metaEntryBase() const -> QString override { return TeamCivitas::metaEntryBase(); }

    inline auto helpPage() const -> QString override { return ""; }
};

class TeamCivitasTexturePackPage : public TexturePackResourcePage {
    Q_OBJECT

   public:
    static TeamCivitasTexturePackPage* create(TexturePackDownloadDialog* dialog, BaseInstance& instance)
    {
        return TexturePackResourcePage::create<TeamCivitasTexturePackPage>(dialog, instance);
    }

    TeamCivitasTexturePackPage(TexturePackDownloadDialog* dialog, BaseInstance& instance);
    ~TeamCivitasTexturePackPage() override = default;

    bool shouldDisplay() const override;

    inline auto displayName() const -> QString override { return TeamCivitas::displayName(); }
    inline auto icon() const -> QIcon override { return TeamCivitas::icon(); }
    inline auto id() const -> QString override { return TeamCivitas::id(); }
    inline auto debugName() const -> QString override { return TeamCivitas::debugName(); }
    inline auto metaEntryBase() const -> QString override { return TeamCivitas::metaEntryBase(); }

    inline auto helpPage() const -> QString override { return ""; }
};

class TeamCivitasShaderPackPage : public ShaderPackResourcePage {
    Q_OBJECT

   public:
    static TeamCivitasShaderPackPage* create(ShaderPackDownloadDialog* dialog, BaseInstance& instance)
    {
        return ShaderPackResourcePage::create<TeamCivitasShaderPackPage>(dialog, instance);
    }

    TeamCivitasShaderPackPage(ShaderPackDownloadDialog* dialog, BaseInstance& instance);
    ~TeamCivitasShaderPackPage() override = default;

    bool shouldDisplay() const override;

    inline auto displayName() const -> QString override { return TeamCivitas::displayName(); }
    inline auto icon() const -> QIcon override { return TeamCivitas::icon(); }
    inline auto id() const -> QString override { return TeamCivitas::id(); }
    inline auto debugName() const -> QString override { return TeamCivitas::debugName(); }
    inline auto metaEntryBase() const -> QString override { return TeamCivitas::metaEntryBase(); }

    inline auto helpPage() const -> QString override { return ""; }
};

class TeamCivitasDataPackPage : public DataPackResourcePage {
    Q_OBJECT

   public:
    static TeamCivitasDataPackPage* create(DataPackDownloadDialog* dialog, BaseInstance& instance)
    {
        return DataPackResourcePage::create<TeamCivitasDataPackPage>(dialog, instance);
    }

    TeamCivitasDataPackPage(DataPackDownloadDialog* dialog, BaseInstance& instance);
    ~TeamCivitasDataPackPage() override = default;

    bool shouldDisplay() const override;

    inline auto displayName() const -> QString override { return TeamCivitas::displayName(); }
    inline auto icon() const -> QIcon override { return TeamCivitas::icon(); }
    inline auto id() const -> QString override { return TeamCivitas::id(); }
    inline auto debugName() const -> QString override { return TeamCivitas::debugName(); }
    inline auto metaEntryBase() const -> QString override { return TeamCivitas::metaEntryBase(); }

    inline auto helpPage() const -> QString override { return ""; }
};

}  // namespace ResourceDownload
