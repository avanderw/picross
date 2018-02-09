package avdw.picross.game;

import haxe.ds.IntMap;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class ColorSelector extends Sprite
{
	static public var ERASER:Int = 0xCCCCCC;
	var size:Int;
	
	public var colors:Map<Int, Sprite> = new IntMap();
	public var selected:Int;
	public var count:Int = 0;

	public function new(size:Int)
	{
		super();
		this.size = size;
		this.selected = ERASER;
	}

	public function putColor(pixel:Int) :Void
	{
		if (!colors.exists(pixel))
		{
			var sprite = createBtn(pixel);
			colors.set(pixel, sprite);
			addChild(sprite);
			count++;
			trace("putColor", pixel);
		}
	}

	public function finalise()
	{

		var sprite = createBtn(ERASER);
		colors.set(ERASER, sprite);
		addChild(sprite);

		var idx = 0;
		for (sprite in colors)
		{
			sprite.x = idx * size;
			idx ++;
		}

	}

	function createBtn(pixel:Int):Sprite
	{
		var sprite = new Sprite();
		sprite.name = cast pixel;
		sprite.graphics.beginFill(pixel, 1);
		sprite.graphics.drawRect(0, 0, size, size);
		sprite.graphics.endFill();

		sprite.addEventListener(MouseEvent.CLICK, select);
		return sprite;
	}

	function select(e:MouseEvent):Void
	{
		selected = cast (cast (e.currentTarget, Sprite).name);
	}

}