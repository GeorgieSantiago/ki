#include "property.h"

void Property::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_target", "target"), &Property::set_target);
	ClassDB::bind_method(D_METHOD("get_target"), &Property::get_target);
    ClassDB::bind_method(D_METHOD("set_prop", "_prop"), &Property::set_prop);
	ClassDB::bind_method(D_METHOD("get_prop"), &Property::get_prop);
    ClassDB::bind_method(D_METHOD("get"), &Property::get);
	
	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "target"),
		"set_target",
		"get_target"
	);

    ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "prop"),
		"set_prop",
		"get_prop"
	);
}

Variant Property::get()
{
    Node* node = this->get_node<Node>(target);
    return node->get(prop);
}