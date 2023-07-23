#include "state.h"

void State::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_props", "_props"), &State::set_props);
	ClassDB::bind_method(D_METHOD("get_props"), &State::get_props);

	ADD_PROPERTY(
		PropertyInfo(Variant::NODE_PATH, "props"),
		"set_props",
		"get_props"
	);

}

//@TODO bind on props change method