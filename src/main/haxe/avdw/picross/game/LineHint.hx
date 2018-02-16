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
		var colorMap = new IntMap<ColorHint>();
		for (idx in 0...line.length)
		{
			for (c in game.colorManager.colors.keys())
			{
				if (!colorMap.exists(c))
				{
					colorMap.set(c, new ColorHint());
				}
				if (line[idx].pixel == c)
				{
					colorMap.get(c).count++;
					if (colorMap.get(c).last == -1) {
						colorMap.get(c).last = idx;
					}
					
					if (!colorMap.get(c).broken) {
						colorMap.get(c).broken = idx - colorMap.get(c).last > 1;
					}
					colorMap.get(c).last = idx;
				}
			}
		}
		
		var idx = 0;
		for (c in colorMap.keys())
		{
			trace("line", c, colorMap.get(c));
			var hint = new Hint(game, c, colorMap.get(c).count, colorMap.get(c).broken);

			if (isRow)
			{
				hint.x = idx * game.gridSize;
			}
			else
			{
				hint.y = idx * game.gridSize;
			}

			addChild(hint);
			idx++;
		}
	}

}

	class ColorHint
	{
		public var broken:Bool;
		public var count:Int;
		public var last:Int;
		
		public function new()
		{
			count = 0;
			last = -1;
			broken = false;
		};

	}