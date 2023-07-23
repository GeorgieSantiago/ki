#ifndef COQUI_STATE_H
#define COQUI_STATE_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include "property.h"

typedef TypedArray<Property> PropertyArray;

using namespace godot;

class State : public Node
{
	GDCLASS(State, Node)
protected:
	static void _bind_methods();
public:
    PropertyArray props;
    PropertyArray get_props() { return props; }
    void set_props(PropertyArray _props) { props = props; }
    void _ready();
};

#endif