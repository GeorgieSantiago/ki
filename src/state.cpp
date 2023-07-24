#include "state.h"

void State::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_props", "_props"), &State::set_props);
	ClassDB::bind_method(D_METHOD("get_props"), &State::get_props);
    // //@TODO this array is causing a segmentation fault
	ADD_PROPERTY(
		PropertyInfo(Variant::PACKED_BYTE_ARRAY, "props"),
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
            arr.push_back(prop);
            Callable callback = Callable::Callable(this, "on_property_list_changed");
            prop->connect("property_list_changed", callback);
        }
    }
	props.resize(arr.size());
	props = arr;
}

void State::on_property_list_changed()
{
    UtilityFunctions::print("Property of state has changed");
}

//@TODO bind on props change method