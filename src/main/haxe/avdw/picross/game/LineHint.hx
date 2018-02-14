package avdw.picross.game;
import flash.display.Sprite;
import haxe.ds.IntMap;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class LineHint extends Sprite
{
	var game:Game;

	public function new(game:Game, line:Array<Block>, isRow:Bool)
	{
		super();
		this.game = game;
		var colorCountMap:IntMap<Int> = countColors(line);

		var idx = 0;
		for (c in colorCountMap.keys())
		{
			trace("line", c, colorCountMap.get(c));
			var hint = new Hint(game, c, colorCountMap.get(c), false);
			
			if (isRow) {
				hint.x = idx * game.gridSize;
			} else {
				hint.y = idx * game.gridSize;
			}
			
			addChild(hint);
			idx++;
		}
	}

	function countColors(line:Array<Block>)
	{
		var colorCountMap = new IntMap();
		for (idx in 0...line.length)
		{
			for (c in game.colorManager.colors.keys())
			{
				if (!colorCountMap.exists(c))
				{
					colorCountMap.set(c, 0);
				}
				if (line[idx].pixel == c)
				{
					colorCountMap.set(c, colorCountMap.get(c)+1);
				}
			}
		}
		return colorCountMap;
	}

}