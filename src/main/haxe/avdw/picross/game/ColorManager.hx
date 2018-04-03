package avdw.picross.game;

import haxe.ds.IntMap;
import openfl.display.BitmapData;
import openfl.display.Sprite;
import openfl.events.MouseEvent;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class ColorManager extends Sprite
{
	static public var ERASER:Int = 0xCCCCCC;
	
	public var colors:Map<Int, Sprite> = new IntMap();
	public var selected:Int;
	public var count:Int = 0;

	public function new(bmd:BitmapData)
	{
		super();
		this.selected = ERASER;
		
		for (y in 0...bmd.height)
		{
			for (x in 0...bmd.width)
			{
				var pixel = bmd.getPixel(x, y);
				putColor(pixel);
			}
		}
	}

	public function putColor(pixel:Int) :Void
	{
		if (!colors.exists(pixel))
		{
			var sprite = new Sprite();
			colors.set(pixel, sprite);
			addChild(sprite);
			count++;
			trace("putColor", pixel);
		}
	}

	public function finalise(spriteSize:Int)
	{
		for (color in colors.keys()) {
			colors.get(color).name = cast color;
			colors.get(color).graphics.beginFill(color, 1);
			colors.get(color).graphics.drawRect(0, 0, spriteSize, spriteSize);
			colors.get(color).graphics.endFill();
			colors.get(color).addEventListener(MouseEvent.CLICK, select);
		}
		
		var eraser = new Sprite();
		eraser.name = cast ERASER;
		eraser.graphics.beginFill(ERASER, 1);
		eraser.graphics.drawRect(0, 0, spriteSize, spriteSize);
		eraser.graphics.endFill();
		eraser.addEventListener(MouseEvent.CLICK, select);
		
		colors.set(ERASER, eraser);
		addChild(eraser);

		var idx = 0;
		for (sprite in colors)
		{
			sprite.x = idx * spriteSize;
			idx ++;
		}
	}
	
	function select(e:MouseEvent):Void
	{
		selected = cast (cast (e.currentTarget, Sprite).name);
	}

}