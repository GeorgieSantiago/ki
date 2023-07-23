#ifndef COQUI_PROPERTY_H
#define COQUI_PROPERTY_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>

using namespace godot;

class Property : public Node
{
	GDCLASS(Property, Node)
protected:
	static void _bind_methods();
public:
    NodePath target;
    void set_target(NodePath path) { target = path; }
    NodePath get_target() { return target; }
    StringName prop;
    void set_prop(StringName _prop) { prop = _prop; }
    StringName get_prop() { return prop; }
    Variant get();
};

#endif