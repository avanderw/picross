package avdw.picross.game;
import flash.display.Sprite;
import haxe.ds.IntMap;
import openfl.text.TextField;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Hint extends Sprite
{
	var game:Game;

	public function new(game:Game, line:Array<Block>)
	{
		super();
		this.game = game;
		var colorCountMap:IntMap<Int> = countColors(line);

		for (c in colorCountMap.keys())
		{
			trace("line", c, colorCountMap.get(c));
			var count = new TextField();
			count.text = ""+colorCountMap.get(c);
			addChild(count);
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