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

	var colors:Map<Int, Sprite> = new IntMap();
	var size:Int;
	var eraser:Int = 0xCCCCCC;
	public var selected:Int;

	public function new(size:Int)
	{
		super();
		this.size = size;
		this.selected = eraser;
	}

	public function putColor(pixel:Int) :Void
	{
		if (!colors.exists(pixel))
		{
			var sprite = createBtn(pixel);
			colors.set(pixel, sprite);
			addChild(sprite);
		}
	}

	public function finalise()
	{
		
		var sprite = createBtn(eraser);
		colors.set(eraser, sprite);
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
		trace("selected", selected);
	}

}