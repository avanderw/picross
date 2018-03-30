package avdw.picross.game;
import openfl.Assets;
import flash.display.Sprite;
import format.SVG;
import haxe.ds.IntMap;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class LineHint extends Sprite
{
	var game:Game;
	var line:Array<Block>;
	var hints:IntMap<Hint>;
	var isLineError:Bool;
	var error:Sprite;

	public function new(game:Game, line:Array<Block>, isRow:Bool)
	{
		super();
		this.game = game;
		this.line = line;
		this.hints = new IntMap<Hint>();

		var colorMap = calculateLineStatus(true);
		var idx = 0;
		for (c in colorMap.keys())
		{
			var hint = new Hint(game, c, colorMap.get(c).count, colorMap.get(c).broken);

			if (isRow)
			{
				hint.x = idx * game.gridSize;
			}
			else
			{
				hint.y = idx * game.gridSize;
			}

			this.hints.set(c, hint);
			addChild(hint);
			idx++;
		}

		var svg:SVG;
		svg = new SVG(Assets.getText("img/error.svg")); // move to app_global area;
		error = new Sprite();
		svg.render(error.graphics);
		var ratio = error.width / error.height;
		error.height = game.gridSize;
		error.width = ratio * game.gridSize;
		var offset = (game.gridSize - error.width) / 2;
		error.alpha = 0;

		if (isRow)
		{
			error.x = idx * game.gridSize + offset;
		}
		else
		{
			error.x = offset;
			error.y = idx * game.gridSize;
		}

		addChild(error);

	}

	public function refresh()
	{
		trace("refreshing");

		isLineError = false;
		var colorMap = calculateLineStatus(false);
		for (h in this.hints)
		{
			var apply = h.count <= colorMap.get(h.color).count;

			if (apply)
			{
				var countBroken = h.count < colorMap.get(h.color).count;
				var brokenBroken = h.broken != colorMap.get(h.color).broken;
				isLineError = isLineError || countBroken || brokenBroken;
			}

			if (h.count == colorMap.get(h.color).count && h.broken == colorMap.get(h.color).broken)
			{
				h.alpha = 0;
			}
			else
			{
				h.alpha = 1;
			}
		}

		error.alpha = (isLineError) ? 1: 0;

	}

	function calculateLineStatus(useBase:Bool):IntMap<ColorHint>
	{
		var colorMap = new IntMap<ColorHint>();
		for (idx in 0...line.length)
		{
			for (c in game.colorManager.colors.keys())
			{
				if (!colorMap.exists(c))
				{
					colorMap.set(c, new ColorHint());
				}
				if ((useBase && line[idx].pixel == c) || (!useBase && line[idx].color == c))
				{
					colorMap.get(c).count++;
					if (colorMap.get(c).last == -1)
					{
						colorMap.get(c).last = idx;
					}

					if (!colorMap.get(c).broken)
					{
						colorMap.get(c).broken = idx - colorMap.get(c).last > 1;
					}
					colorMap.get(c).last = idx;
				}
			}
		}

		return colorMap;
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