package avdw.picross.game;
import haxe.ds.IntMap;
import openfl.display.Sprite;
import openfl.text.TextField;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class Hints extends Sprite
{
	public var rowHintsContainer:Sprite;
	public var colHintsContainer:Sprite;

	var colorSelector:ColorSelector;
	var game:Game;

	public function new(game:Game)
	{
		super();
		this.game = game;
		this.rowHintsContainer = new Sprite();
		this.colHintsContainer = new Sprite();

		for (y in 0...game.blocks.length)
		{
			var colorCountMap = new IntMap();
			for (x in 0...game.blocks[0].length)
			{
				for (c in game.colorSelector.colors.keys())
				{
					if (game.blocks[y][x].pixel == c)
					{
						if (!colorCountMap.exists(c))
						{
							colorCountMap.set(c, 0);
						}
						colorCountMap.set(c, colorCountMap.get(c)+1);
					}
				}
			}

			var rowHint = new Sprite();
			rowHintsContainer.addChild(rowHint);
			for (c in colorCountMap.keys())
			{
				trace("row", y, c, colorCountMap.get(c));
				var hint = new Sprite();
				var hintText = new TextField();
				hintText.text = ""+colorCountMap.get(c);
				hint.addChild(hintText);
				rowHint.addChild(hint);
			}
		}

		for (x in 0...game.blocks[0].length)
		{
			var colorCountMap = new IntMap();
			for (y in 0...game.blocks.length)
			{
				for (c in game.colorSelector.colors.keys())
				{
					if (game.blocks[y][x].pixel == c)
					{
						if (!colorCountMap.exists(c))
						{
							colorCountMap.set(c, 0);
						}
						colorCountMap.set(c, colorCountMap.get(c)+1);
					}
				}
			}
			
			var colHint = new Sprite();
			colHintsContainer.addChild(colHint);
			for (c in colorCountMap.keys())
			{
				trace("col", x, c, colorCountMap.get(c));
				var hint = new Sprite();
				var hintText = new TextField();
				hintText.text = ""+colorCountMap.get(c);
				hint.addChild(hintText);
				colHint.addChild(hint);
			}
		}
		
		rowHintsContainer.y = 5 * game.gridSize;
		colHintsContainer.x =  5 * game.gridSize;
		
		addChild(rowHintsContainer);
		addChild(colHintsContainer);
	}

	public function refresh()
	{

	}

}