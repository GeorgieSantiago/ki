extends Cue

@export var target_node: Node3D
@export var area_node: Area3D

#in this case the invoker is the Area3D
#for use later
func _ready():
	area_node.connect("area_entered", _on_area_entered)
	
func _on_area_entered(other):
	if target_node == null:
		invoke(self)
	elif other == target_node:
		invoke(self)
