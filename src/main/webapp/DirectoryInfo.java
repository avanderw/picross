
import com.google.gson.GsonBuilder;
import java.util.ArrayList;
import java.util.List;

public class DirectoryInfo {

    public final String url;
    public List<DirectoryInfo> directories = new ArrayList();
    public List<LevelInfo> levels = new ArrayList();

    DirectoryInfo(String url) {
        this.url = url;
    }

    @Override
    public String toString() {
        return new GsonBuilder().setPrettyPrinting().create().toJson(this);
    }

    void add(DirectoryInfo info) {
        this.directories.add(info);
    }

    void add(LevelInfo info) {
        this.levels.add(info);
    }
}
