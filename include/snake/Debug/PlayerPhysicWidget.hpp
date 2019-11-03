#ifndef PLAYERPHYSICWIDGET_H
#define PLAYERPHYSICWIDGET_H

#include <snake/Eventer/EventManager.hpp>
#include <snake/Core/EntityComponentSystem/World.hpp>
#include <snake/Physic/Body.hpp>
#include <imgui_sfml/imgui.h>

namespace snake::debug {

    static void HelpMarker(const char* desc) {
        ImGui::TextDisabled("(?)");
        if (ImGui::IsItemHovered())
        {
            ImGui::BeginTooltip();
            ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
            ImGui::TextUnformatted(desc);
            ImGui::PopTextWrapPos();
            ImGui::EndTooltip();
        }
    }
    
    class PlayerPhysicWidget {
    public:
        PlayerPhysicWidget(core::Entity *const entity, eventer::EventManager* eventManager, core::World* World);
        void show(bool* isOpen);
    private:
        void showBodyPhysicComponentsAttributes();
        void createBodyPhysicComponentsAttributesTable();
        void createExtendBodyButton(const char* label);
        template<typename Component> void disableComponent(const char* label) {
            static bool disableRenderComponent = false;
            ImGui::Checkbox(label, &disableRenderComponent);
            if(disableRenderComponent) {
                world->detach<Component>(entity);
            }else {
                world->attach<Component>(entity);
            }
        }

        void fillTable();
        void makeRowSelectable(int row, int* selected);
        void fillRowWithBodyPhysicComponentsAttributes(physic::PhysicComponent const& segment);
    private:
        core::Entity *const entity;
        eventer::EventManager* eventManager;
        core::World* world;
    };
}

#endif /* PLAYERPHYSICWIDGET_H */
