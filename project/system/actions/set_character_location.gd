extends Action

@export var character_ptr: Character
@export var target: Node3D

func _execute(_invoker: Variant):
	character_ptr.handle_navigation(target.global_position)
	return 0
