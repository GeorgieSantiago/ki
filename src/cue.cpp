#include "cue.h"

void Cue::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("invoke", "invoker"), &Cue::invoke);
    ClassDB::bind_method(D_METHOD("in_editor"), &Cue::in_editor);
}

bool Cue::in_editor()
{
    return Engine::get_singleton()->is_editor_hint();
}

void Cue::invoke(Variant invoker)
{
    int cnt = get_child_count();
    for (int i = 0;i < cnt;i++)
    {
        Node* child = get_child(i);
        Action* _action = Object::cast_to<Action>(child);
        if (_action != nullptr)
        {
            _action->_execute(invoker);
            if (_action->has_method("_execute"))
            {
                _action->call("_execute", invoker);
            }

        }
    }
}