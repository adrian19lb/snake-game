#include <snake/Debug/PlayerPhysicWidget.hpp>
#include <snake/Physic/Movement/ConstantMovementComponent.hpp>
#include <snake/Game/Score/OverallScoreComponent.hpp>
#include <snake/Renderer/RenderComponents.hpp>
#include <snake/Game/Teleport/TeleportAcrossAxisComponent.hpp>
#include <imgui_sfml/imgui.h>
#include <imgui_sfml/imgui-SFML.h>
#include <cstdio>
#include <SFML/Graphics/Sprite.hpp>

namespace snake::debug {
       
    PlayerPhysicWidget::PlayerPhysicWidget(core::Entity *const entity, eventer::EventManager* eventManager, core::World* world)
    : entity(entity)
    , eventManager(eventManager)
    , world(world) {
        
    }

    void PlayerPhysicWidget::show(bool* isOpen) {
        ImGui::Begin("Player");
        if (ImGui::CollapsingHeader("Components options")) {
            createExtendBodyButton("Extend body tail");
            disableComponent<physic::ConstantMovementComponent>("Disable ConstantMovementComponent");
            disableComponent<game::OverallScoreComponent>("Disable OverallScoreComponent");
            disableComponent<renderer::RenderComponents>("Disable RenderComponents");
        }

        if (ImGui::CollapsingHeader("Render options")) {
            if (ImGui::TreeNode("Color")) {
                static ImVec4 color = ImVec4(114.0f/255.0f, 144.0f/255.0f, 154.0f/255.0f, 200.0f/255.0f);

                static bool alpha_preview = true;
                static bool alpha_half_preview = false;
                static bool options_menu = true;
                ImGui::Checkbox("With Alpha Preview", &alpha_preview);
                ImGui::Checkbox("With Half Alpha Preview", &alpha_half_preview);
                ImGui::Checkbox("With Options Menu", &options_menu); ImGui::SameLine(); HelpMarker("Right-click on the individual color widget to show options.");
                ImGuiColorEditFlags misc_flags = (alpha_half_preview ? ImGuiColorEditFlags_AlphaPreviewHalf : (alpha_preview ? ImGuiColorEditFlags_AlphaPreview : 0)) | (options_menu ? 0 : ImGuiColorEditFlags_NoOptions);
                ImGui::Separator();
                ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
                ImGui::Text("Color palette");
                ImGui::Separator();
                ImGui::ColorPicker4("##picker", (float*)&color, misc_flags);

                auto renderComponents = world->getComponentsManager().pull<renderer::RenderComponents>(entity);
                renderComponents->fillColor.r = static_cast<sf::Uint8>(color.x * 255.f);
                renderComponents->fillColor.g = static_cast<sf::Uint8>(color.y * 255.f);
                renderComponents->fillColor.b = static_cast<sf::Uint8>(color.z * 255.f);
                renderComponents->fillColor.a = static_cast<sf::Uint8>(color.w * 255.f);
                ImGui::Text("Preview");
                ImGui::Image(*renderComponents->texture, renderComponents->fillColor); 
                ImGui::TreePop();
            }
        
        }

        if ( ImGui::CollapsingHeader("Body") ) {
            showBodyPhysicComponentsAttributes();
        }

        
        ImGui::End(); 
    }

    void PlayerPhysicWidget::createExtendBodyButton(const char* label) {
        static int clicked = 0;
        if (ImGui::Button(label))
            clicked++;
        if (clicked == 1) {
            auto entityBody = world->getComponentsManager().pull<physic::Body>(entity);
            entityBody->cloneTail();
            --clicked;
        }
    }

    void PlayerPhysicWidget::showBodyPhysicComponentsAttributes() {
        if (ImGui::TreeNode("PhysicComponents attributes")) {
            createBodyPhysicComponentsAttributesTable();
            fillTable();
            ImGui::TreePop();
        }
    }
        
    void PlayerPhysicWidget::createBodyPhysicComponentsAttributesTable() {
        ImGui::Separator();
        ImGui::Columns(5, "PhysicComponents physic context", true);
        ImGui::Text("ID"); ImGui::NextColumn();
        ImGui::Text("Position"); ImGui::NextColumn();
        ImGui::Text("Origin"); ImGui::NextColumn();
        ImGui::Text("Size"); ImGui::NextColumn();
        ImGui::Text("Angle"); ImGui::NextColumn();
        ImGui::Separator();
    }
        
    void PlayerPhysicWidget::fillTable() {
        int i = 0;
        static int selected = -1;
        auto entityBody = world->getComponentsManager().pull<physic::Body>(entity);
        for (auto&& segment :*entityBody) {
            makeRowSelectable(i, &selected);
            fillRowWithBodyPhysicComponentsAttributes(segment);
            ++i; 
        }
    }
        
    void PlayerPhysicWidget::makeRowSelectable(int row, int* selected) {
        char label[32];
        sprintf(label, "%02d", row);
        if (ImGui::Selectable(label, *selected == row, ::ImGuiSelectableFlags_SpanAllColumns )) {
            *selected = row;
        }
    }
        
    void PlayerPhysicWidget::fillRowWithBodyPhysicComponentsAttributes(physic::PhysicComponent const& segment) {
        ImGui::NextColumn();
        ImGui::Text("%.3f   %.3f", segment.position.x, segment.position.y); ImGui::NextColumn();
        ImGui::Text("%.3f   %.3f", segment.origin.x, segment.origin.y); ImGui::NextColumn();
        ImGui::Text("%.3f   %.3f", segment.size.x, segment.size.y); ImGui::NextColumn();
        ImGui::Text("%.0f", segment.angle); ImGui::NextColumn();
        ImGui::Separator();
    }

}
