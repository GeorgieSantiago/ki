#ifndef KI_STATE_H
#define KI_STATE_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include "property.h"

typedef TypedArray<Property> PropertyArray;

using namespace godot;

class State : public Node
{
	GDCLASS(State, Node)
protected:
	static void _bind_methods();
public:
    TypedArray<Property> props;
    TypedArray<Property> get_props() { return props; }
    void set_props(TypedArray<Property> _props) { props = _props; }
    void _ready();
    void on_property_updated(Variant target);
    String get_property_path_relative_to_state(NodePath prop);

};

#endif