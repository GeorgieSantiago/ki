extends Cue

@export var area_node: Area3D

func _ready():
	area_node.connect("area_entered", _on_area_entered)
	
func _on_area_entered(other: Area3D):
	print_rich(other)
