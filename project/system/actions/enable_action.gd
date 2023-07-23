extends Node

@export var enabled: bool
@export var target: NodePath

#Figure out how to properly do this
func _execute(_invoker: Variant):
	if enabled:
		remove_child(get_node(target))
	else:
		add_child(get_node(target))
	return 0
