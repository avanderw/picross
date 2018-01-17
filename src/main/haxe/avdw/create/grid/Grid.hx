package avdw.create.grid;

import openfl.display.Sprite;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Grid extends Sprite
{

	public function new(rows:Int, cols:Int, size:Int, guides:Bool = false)
	{
		super();
		addChild(Grid.create(rows, cols, size, guides));
	}
	
	public static function create(rows:Int, cols:Int, size:Int, guides:Bool = false):Sprite 
	{
		var gfx:Sprite = new Sprite();
		
		if (guides) {
			gfx.graphics.beginFill(0xe6e6e6);
            gfx.graphics.drawRect(0, Math.floor(rows * 1 / 4) * size, cols * size, size);
            gfx.graphics.drawRect(0, Math.floor(rows * 3 / 4) * size, cols * size, size);
            gfx.graphics.endFill();

            gfx.graphics.beginFill(0xcccccc);
            gfx.graphics.drawRect(Math.floor(cols / 2) * size, 0, size, rows * size);
            gfx.graphics.drawRect(0, Math.floor(rows / 2) * size, cols * size, size);
            gfx.graphics.endFill();
		}
		
		gfx.graphics.lineStyle(1, 0x999999);
        for (y in 0...rows) {
            gfx.graphics.moveTo(0, y * size);
            gfx.graphics.lineTo(cols * size, y * size);
        }

        for (x in 0...cols) {
            gfx.graphics.moveTo(x * size, 0);
            gfx.graphics.lineTo(x * size, rows * size);
        }
		
		return gfx;
	}
	
}