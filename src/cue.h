#ifndef COQUI_CUE_H
#define COQUI_CUE_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/variant/signal.hpp>
#include <godot_cpp/classes/engine.hpp>
#include "action.h"

using namespace godot;

class Cue : public Node
{
	GDCLASS(Cue, Node)
protected:
	static void _bind_methods();
public:

	StringName event_name;
	StringName get_event_name();
	void set_event_name(StringName _name);

	Array actions;
	void invoke(Variant invoker);
	bool in_editor();
};

#endif//! COQUI_CUE_H