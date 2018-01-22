package avdw.pattern;
import haxe.Serializer;
import haxe.Unserializer;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Memento
{
	var state:Dynamic;
	var history:Array<String>;

	public function new(state:Dynamic)
	{
		this.state = state;
		this.history = [];
	}

	public function save()
	{
		var serializer:Serializer = new Serializer();
		serializer.serialize(state);
		history.push(serializer.toString());
	}

	public function restore()
	{
		var unserializer = new Unserializer(history.pop());
		var obj = unserializer.unserialize();
		for (field in Reflect.fields(obj)) {
			Reflect.setField(this.state, field, Reflect.field(obj, field));
		}
	}

}