#ifndef KI_ACTION_H
#define KI_ACTION_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/object.hpp>
#include <godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

using namespace godot;

class Action : public Node
{
	GDCLASS(Action, Node)
protected:
	static void _bind_methods() {
		BIND_VIRTUAL_METHOD(Action, _execute);
	}
public:
	virtual int _execute(Variant invoker) { return 0; };
};


#endif//! KI_ACTION_H