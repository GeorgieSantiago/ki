extends Action

class_name DebugAction

@export var message: String
@export var color: Color

func _execute(_invoker: Variant) -> int:
	print_rich("[color=" + color.to_html() + "] " + message)
	return 0
