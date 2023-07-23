extends Action

@export var spawnable: PackedScene
@export var parent: Node3D
@export var position: Vector3

func _execute(_invoker: Variant):
	var instance = spawnable.instantiate() as Node3D
	instance.position = position
	if parent == null:
		add_child(instance)
	else:
		parent.add_child(instance)
	return 0
