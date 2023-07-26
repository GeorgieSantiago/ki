#ifndef KI_CINEMA_H
#define KI_CINEMA_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/classes/input_event.hpp>
#include <godot_cpp/classes/camera3d.hpp>

using namespace godot;

class Cinema : public Camera3D
{
    GDCLASS(Cinema, Camera3D)
    enum Mode {
        FREE = 0
    };

protected:
    static void _bind_methods();
public:
    Mode mode;
    Mode get_mode() { return mode; }
    void set_mode(Mode _mode) { mode = _mode; }
    void _physics_process(float delta);
    void _unhandled_input(const Ref<InputEvent> event); 
};

VARIANT_ENUM_CAST(Cinema::Mode);


#endif