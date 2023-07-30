#include "cinema.h"

void Cinema::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_speed", "_speed"), &Cinema::set_speed);
    ClassDB::bind_method(D_METHOD("get_speed"), &Cinema::get_speed);
    ClassDB::bind_method(D_METHOD("set_mode", "_mode"), &Cinema::set_mode);
    ClassDB::bind_method(D_METHOD("get_mode"), &Cinema::get_mode);
    ClassDB::bind_method(D_METHOD("set_target", "_target"), &Cinema::set_target);
    ClassDB::bind_method(D_METHOD("get_target"), &Cinema::get_target);

    ADD_PROPERTY(
        PropertyInfo(Variant::INT, "speed"),
        "set_speed",
        "get_speed"
    );

    ADD_PROPERTY(
        PropertyInfo(Variant::INT, "mode"),
        "set_mode",
        "get_mode"
    );

    ADD_PROPERTY(
        PropertyInfo(Variant::NODE_PATH, "target"),
        "set_target",
        "get_target"
    );

}

void Cinema::_ready()
{
    if (speed <= 0) {
        speed = 1;
    }
    if (!Engine::get_singleton()->is_editor_hint()) {
        Input::get_singleton()->set_mouse_mode(Input::MouseMode::MOUSE_MODE_CAPTURED);
    }
}


//@TODO create different camera controls
/**
* - Free Camera
* - Follow Camera
* - Fixed Camera (With and without target) 
*/
void Cinema::_physics_process(float delta)
{
    if (Engine::get_singleton()->is_editor_hint()) {
        return;
    }

    if (mode == Mode::FREE) { 
        Input* input = Input::get_singleton();
        float z = input->is_action_pressed(UP) ? -1 : 0;
        z += input->is_action_pressed(DOWN) ? 1 : 0;
        float x = input->is_action_pressed(RIGHT) ? 1 : 0;
        x  += input->is_action_pressed(LEFT) ? -1 : 0;
        Vector3 movement = Vector3(x * delta * speed, 0, z * delta * speed);
        set_position(get_position() + movement);
        if (input->get_last_mouse_velocity() != Vector2())
        {
            UtilityFunctions::print("Mouse moved");
        }
    }
}

void Cinema::_unhandled_input(const Ref<InputEvent> event)
{
    
    //@TODO Camera rotation controlled by mouse
}