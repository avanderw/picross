
import com.google.gson.Gson;
import java.util.ArrayList;
import java.util.List;

public class DirectoryInfo {
    public List<String> directories = new ArrayList();
    public List<LevelInfo> levels = new ArrayList();

    @Override
    public String toString() {
        return new Gson().toJson(this);
    }
}
