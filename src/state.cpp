#include "state.h"

void State::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_props", "_props"), &State::set_props);
	ClassDB::bind_method(D_METHOD("get_props"), &State::get_props);
    ClassDB::bind_method(D_METHOD("get_property_path_relative_to_state", "prop"), &State::get_property_path_relative_to_state);
    ClassDB::bind_method(D_METHOD("on_property_updated", "target"), &State::on_property_updated);
	ADD_PROPERTY(
		PropertyInfo(Variant::ARRAY, "props"),
		"set_props",
		"get_props"
	);
}

void State::_ready()
{
	int cnt = get_child_count();
	TypedArray<Property> arr;
    for (int i = 0;i < cnt;i++)
    {
        Node* child = get_child(i);
        Property* prop = Object::cast_to<Property>(child);
        if (prop != nullptr)
        {
            Callable callback = Callable(this, StringName("on_property_updated"));
            prop->connect("on_property_updated", callback);
            arr.push_back(prop);
        }
    }
	props.resize(arr.size());
	props = arr;
}

void State::on_property_updated(Variant target)
{
    UtilityFunctions::print("Property of state has changed");
}

String State::get_property_path_relative_to_state(NodePath prop)
{
    Property* _prop = get_node<Property>(prop);
    int size = _prop->target.get_name_count() - 1;
    Array names;
    for (int i = 0; i < _prop->target.get_name_count();i++)
    {
        if (i != 0)
        {
            names[i - 1] = _prop->target.get_name(i);
        }
    }
    return UtilityFunctions::str(names);
}