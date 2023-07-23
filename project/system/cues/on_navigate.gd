extends Cue

@export var path_finder: PathFollow3D

func _ready():
	path_finder.connect("path_finder_location_change", _on_change)

func _on_change():
	invoke(self)

