// SPDX-FileCopyrightText: 2023 flowln <flowlnlnln@gmail.com>
//
// SPDX-License-Identifier: GPL-3.0-only
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

#include "TeamCivitasResourcePages.h"
#include "ui/pages/modplatform/DataPackModel.h"
#include "ui_ResourcePage.h"

#include "modplatform/modrinth/ModrinthAPI.h"

#include "ui/dialogs/ResourceDownloadDialog.h"

namespace ResourceDownload {

TeamCivitasModPage::TeamCivitasModPage(ModDownloadDialog* dialog, BaseInstance& instance) : ModPage(dialog, instance)
{
    m_model = new ModModel(instance, new ModrinthAPI(), TeamCivitas::debugName(), TeamCivitas::metaEntryBase());
    m_ui->packView->setModel(m_model);

    addSortings();

    // sometimes Qt just ignores virtual slots and doesn't work as intended it seems,
    // so it's best not to connect them in the parent's constructor...
    connect(m_ui->sortByBox, &QComboBox::currentIndexChanged, this, &TeamCivitasModPage::triggerSearch);
    connect(m_ui->packView->selectionModel(), &QItemSelectionModel::currentChanged, this, &TeamCivitasModPage::onSelectionChanged);
    connect(m_ui->versionSelectionBox, &QComboBox::currentIndexChanged, this, &TeamCivitasModPage::onVersionSelectionChanged);
    connect(m_ui->resourceSelectionButton, &QPushButton::clicked, this, &TeamCivitasModPage::onResourceSelected);

    m_ui->packDescription->setMetaEntry(metaEntryBase());
}

TeamCivitasResourcePackPage::TeamCivitasResourcePackPage(ResourcePackDownloadDialog* dialog, BaseInstance& instance)
    : ResourcePackResourcePage(dialog, instance)
{
    m_model = new ResourcePackResourceModel(instance, new ModrinthAPI(), TeamCivitas::debugName(), TeamCivitas::metaEntryBase());
    m_ui->packView->setModel(m_model);

    addSortings();

    // sometimes Qt just ignores virtual slots and doesn't work as intended it seems,
    // so it's best not to connect them in the parent's constructor...
    connect(m_ui->sortByBox, &QComboBox::currentIndexChanged, this, &TeamCivitasResourcePackPage::triggerSearch);
    connect(m_ui->packView->selectionModel(), &QItemSelectionModel::currentChanged, this, &TeamCivitasResourcePackPage::onSelectionChanged);
    connect(m_ui->versionSelectionBox, &QComboBox::currentIndexChanged, this, &TeamCivitasResourcePackPage::onVersionSelectionChanged);
    connect(m_ui->resourceSelectionButton, &QPushButton::clicked, this, &TeamCivitasResourcePackPage::onResourceSelected);

    m_ui->packDescription->setMetaEntry(metaEntryBase());
}

TeamCivitasTexturePackPage::TeamCivitasTexturePackPage(TexturePackDownloadDialog* dialog, BaseInstance& instance)
    : TexturePackResourcePage(dialog, instance)
{
    m_model = new TexturePackResourceModel(instance, new ModrinthAPI(), TeamCivitas::debugName(), TeamCivitas::metaEntryBase());
    m_ui->packView->setModel(m_model);

    addSortings();

    // sometimes Qt just ignores virtual slots and doesn't work as intended it seems,
    // so it's best not to connect them in the parent's constructor...
    connect(m_ui->sortByBox, &QComboBox::currentIndexChanged, this, &TeamCivitasTexturePackPage::triggerSearch);
    connect(m_ui->packView->selectionModel(), &QItemSelectionModel::currentChanged, this, &TeamCivitasTexturePackPage::onSelectionChanged);
    connect(m_ui->versionSelectionBox, &QComboBox::currentIndexChanged, this, &TeamCivitasTexturePackPage::onVersionSelectionChanged);
    connect(m_ui->resourceSelectionButton, &QPushButton::clicked, this, &TeamCivitasTexturePackPage::onResourceSelected);

    m_ui->packDescription->setMetaEntry(metaEntryBase());
}

TeamCivitasShaderPackPage::TeamCivitasShaderPackPage(ShaderPackDownloadDialog* dialog, BaseInstance& instance)
    : ShaderPackResourcePage(dialog, instance)
{
    m_model = new ShaderPackResourceModel(instance, new ModrinthAPI(), TeamCivitas::debugName(), TeamCivitas::metaEntryBase());
    m_ui->packView->setModel(m_model);

    addSortings();

    // sometimes Qt just ignores virtual slots and doesn't work as intended it seems,
    // so it's best not to connect them in the parent's constructor...
    connect(m_ui->sortByBox, &QComboBox::currentIndexChanged, this, &TeamCivitasShaderPackPage::triggerSearch);
    connect(m_ui->packView->selectionModel(), &QItemSelectionModel::currentChanged, this, &TeamCivitasShaderPackPage::onSelectionChanged);
    connect(m_ui->versionSelectionBox, &QComboBox::currentIndexChanged, this, &TeamCivitasShaderPackPage::onVersionSelectionChanged);
    connect(m_ui->resourceSelectionButton, &QPushButton::clicked, this, &TeamCivitasShaderPackPage::onResourceSelected);

    m_ui->packDescription->setMetaEntry(metaEntryBase());
}

TeamCivitasDataPackPage::TeamCivitasDataPackPage(DataPackDownloadDialog* dialog, BaseInstance& instance) : DataPackResourcePage(dialog, instance)
{
    m_model = new DataPackResourceModel(instance, new ModrinthAPI(), TeamCivitas::debugName(), TeamCivitas::metaEntryBase());
    m_ui->packView->setModel(m_model);

    addSortings();

    // sometimes Qt just ignores virtual slots and doesn't work as intended it seems,
    // so it's best not to connect them in the parent's constructor...
    connect(m_ui->sortByBox, &QComboBox::currentIndexChanged, this, &TeamCivitasDataPackPage::triggerSearch);
    connect(m_ui->packView->selectionModel(), &QItemSelectionModel::currentChanged, this, &TeamCivitasDataPackPage::onSelectionChanged);
    connect(m_ui->versionSelectionBox, &QComboBox::currentIndexChanged, this, &TeamCivitasDataPackPage::onVersionSelectionChanged);
    connect(m_ui->resourceSelectionButton, &QPushButton::clicked, this, &TeamCivitasDataPackPage::onResourceSelected);

    m_ui->packDescription->setMetaEntry(metaEntryBase());
}

// I don't know why, but doing this on the parent class makes it so that
// other mod providers start loading before being selected, at least with
// my Qt, so we need to implement this in every derived class...
auto TeamCivitasModPage::shouldDisplay() const -> bool
{
    return true;
}
auto TeamCivitasResourcePackPage::shouldDisplay() const -> bool
{
    return true;
}
auto TeamCivitasTexturePackPage::shouldDisplay() const -> bool
{
    return true;
}
auto TeamCivitasShaderPackPage::shouldDisplay() const -> bool
{
    return true;
}
auto TeamCivitasDataPackPage::shouldDisplay() const -> bool
{
    return true;
}

std::unique_ptr<ModFilterWidget> TeamCivitasModPage::createFilterWidget()
{
    return ModFilterWidget::create(&static_cast<MinecraftInstance&>(m_baseInstance), true);
}

void TeamCivitasModPage::prepareProviderCategories()
{
    auto response = std::make_shared<QByteArray>();
    m_categoriesTask = ModrinthAPI::getModCategories(response);
    connect(m_categoriesTask.get(), &Task::succeeded, [this, response]() {
        auto categories = ModrinthAPI::loadModCategories(response);
        m_filter_widget->setCategories(categories);
    });
    m_categoriesTask->start();
};
}  // namespace ResourceDownload
