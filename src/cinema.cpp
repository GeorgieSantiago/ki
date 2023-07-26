#include "cinema.h"

void Cinema::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_mode", "_mode"), &Cinema::set_mode);
    ClassDB::bind_method(D_METHOD("get_mode"), &Cinema::get_mode);

    ADD_PROPERTY(
        PropertyInfo(Variant::INT, "mode"),
        "set_mode",
        "get_mode"
    );
}


//@TODO create different camera controls
/**
* - Free Camera
* - Follow Camera
* - Fixed Camera (With and without target) 
*/
void Cinema::_physics_process(float delta)
{
    //@TODO
}

void Cinema::_unhandled_input(const Ref<InputEvent> event)
{
    //@TODO
}