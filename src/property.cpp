#include "property.h"

void Property::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_target", "target"), &Property::set_target);
	ClassDB::bind_method(D_METHOD("get_target"), &Property::get_target);
    ClassDB::bind_method(D_METHOD("set_prop", "_prop"), &Property::set_prop);
	ClassDB::bind_method(D_METHOD("get_prop"), &Property::get_prop);
    ClassDB::bind_method(D_METHOD("value"), &Property::value);
    ClassDB::bind_method(D_METHOD("key"), &Property::key);
    ClassDB::bind_method(D_METHOD("set_state"), &Property::set_state);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "target"),
		"set_target",
		"get_target"
	);

    ADD_PROPERTY(
		PropertyInfo(Variant::STRING_NAME, "prop"),
		"set_prop",
		"get_prop"
	);

	ADD_SIGNAL(MethodInfo("on_property_updated", PropertyInfo(Variant::OBJECT, "target")));
	ClassDB::bind_method(D_METHOD("emit_on_property_changed"), &Property::emit_on_property_changed);

}

Variant Property::value()
{
    return get_node_ptr()->get(prop);
}

StringName Property::key()
{
    return get_node_ptr()->get_name();
}

void Property::emit_on_property_changed()
{
	emit_signal("on_property_updated", this);
}

void Property::set_state(Variant value)
{
    get_node_ptr()->set(prop, value);
	emit_on_property_changed();
}

Node* Property::get_node_ptr()
{
    return this->get_node<Node>(target);
}