#ifndef KI_CINEMA_H
#define KI_CINEMA_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/camera3d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/engine.hpp>

using namespace godot;

class Cinema : public Camera3D
{
    GDCLASS(Cinema, Camera3D)
    enum Mode {
        FREE = 0,
        FOLLOW,
        FIXED
    };

    const char* UP = "ui_up";
    const char* DOWN = "ui_down";
    const char* LEFT = "ui_left";
    const char* RIGHT = "ui_right";
protected:
    static void _bind_methods();
public:

    int speed;
    int get_speed() { return speed; }
    void set_speed(int _speed) { speed = _speed; }

    Mode mode;
    Mode get_mode() { return mode; }
    void set_mode(Mode _mode) { mode = _mode; }

    NodePath target;
    NodePath get_target() { return target; }
    void set_target(NodePath _target) { target = _target; }

    void _ready();
    void _physics_process(float delta);
    void _unhandled_input(const Ref<InputEvent> event); 
};

VARIANT_ENUM_CAST(Cinema::Mode);


#endif