package avdw.picross.game;
import haxe.ds.IntMap;
import openfl.display.Sprite;
import openfl.text.TextField;

/**
 * ...
 * @author Andrew van der Westhuizen
 */
class HintContainer extends Sprite
{
	public var rowHints:Sprite;
	public var colHints:Sprite;

	var game:Game;

	public function new(game:Game)
	{
		super();
		this.game = game;
		this.rowHints = new Sprite();
		this.colHints = new Sprite();

		for (idx in 0...game.blockContainer.rows.length)
		{
			

			var rowHint = new Hint(game, game.blockContainer.rows[idx]);
			rowHints.addChild(rowHint);
			for (c in colorCountMap.keys())
			{
				trace("row", idx, c, colorCountMap.get(c));
				var hint = new Sprite();
				var hintText = new TextField();
				hintText.text = ""+colorCountMap.get(c);
				hint.addChild(hintText);
				rowHint.addChild(hint);
			}
		}

		for (idx in 0...game.blockContainer.cols.length)
		{
			var colorCountMap:IntMap<Int> = countColors(game.blockContainer.cols[idx]);

			var colHint = new Sprite();
			colHints.addChild(colHint);
			for (c in colorCountMap.keys())
			{
				trace("col", idx, c, colorCountMap.get(c));
				var hint = new Sprite();
				var hintText = new TextField();
				hintText.text = ""+colorCountMap.get(c);
				hint.addChild(hintText);
				colHint.addChild(hint);
			}
		}

		rowHints.y = 5 * game.gridSize;
		colHints.x =  5 * game.gridSize;

		addChild(rowHints);
		addChild(colHints);
	}

	

	public function refresh()
	{

	}

}