package avdw.picross.game;
import flash.display.Sprite;
import openfl.display.BitmapData;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class BlockContainer extends Sprite
{

	public var rows:Array<Array<Block>> = new Array();
	public var cols:Array<Array<Block>> = new Array();
	
	public function new(game:Game, bmd:BitmapData) 
	{
		super();
		
		for (y in 0...bmd.height)
		{
			var line = new Array<Block>();
			for (x in 0...bmd.width)
			{
				var pixel = bmd.getPixel(x, y);
				game.colorManager.putColor(pixel);
				
				var block = new Block(game, pixel, game.gridSize);
				block.x = x * game.gridSize;
				block.y = y * game.gridSize;

				line.push(block);
				addChild(block);
			}
			rows.push(line);
		}
		
		for (x in 0...bmd.width) {
			var line = new Array<Block>();
			for (y in 0...bmd.height)
			{
				line.push(rows[y][x]);
			}
			cols.push(line);
		}

		trace("...created blocks");
	}
	
}