```ui
enum(selected_map, "🗺 Select", 220, ["Faerun", "Waterdeep"])

if(starts_with(selected_map, "Faerun")){ map(faerun_map, 400, 400) }
if(starts_with(selected_map, "Waterdeep")){ map(waterdeep_map, 400, 400) }
```