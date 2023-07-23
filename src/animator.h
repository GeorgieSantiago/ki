#ifndef COQUI_ANIMATOR_H
#define COQUI_ANIMATOR_H

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/animation_tree.hpp>

using namespace godot;

class Animator : public AnimationTree
{
	GDCLASS(Animator, AnimationTree)
protected:
	static void _bind_methods() {};
};

#endif