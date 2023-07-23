extends Action

class_name DebugAction

@export var message: String

func _execute(_invoker: Variant) -> int:
	print(message)
	return 0
