package avdw.picross.game;
import openfl.display.Sprite;

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
			var hint = new LineHint(game, game.blockContainer.rows[idx], true);
			hint.y = idx * game.gridSize;
			rowHints.addChild(hint);
		}

		for (idx in 0...game.blockContainer.cols.length)
		{
			var hint = new LineHint(game, game.blockContainer.cols[idx], false);
			hint.x = idx * game.gridSize;
			colHints.addChild(hint);
		}

		rowHints.y = 5 * game.gridSize;
		colHints.x =  5 * game.gridSize;

		addChild(rowHints);
		addChild(colHints);
	}

	public function refresh(xIdx:Int, yIdx:Int)
	{
		trace("refreshing hints", xIdx, yIdx);
		cast (this.rowHints.getChildAt(yIdx), LineHint).refresh();
		cast (this.colHints.getChildAt(xIdx), LineHint).refresh();
	}

}