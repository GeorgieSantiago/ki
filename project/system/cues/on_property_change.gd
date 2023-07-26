extends Cue

class_name OnPropertyChange

@export var property: Property

func _ready():
	property.connect("on_property_updated", self.invoke)
