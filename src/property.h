#ifndef KI_PROPERTY_H
#define KI_PROPERTY_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class Property : public Node
{
	GDCLASS(Property, Node)
private:
    Node* get_node_ptr();
protected:
	static void _bind_methods();
public:
    NodePath target;
    void set_target(NodePath path) { target = path; }
    NodePath get_target() { return target; }
    StringName prop;
    void set_prop(StringName _prop) { prop = _prop; }
    StringName get_prop() { return prop; }
    Variant value();
    StringName key();
    void set_state(Variant value);
    void emit_on_property_changed();
};

#endif