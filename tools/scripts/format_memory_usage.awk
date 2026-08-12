# Build helper: convert GNU ld --print-memory-usage output into a readable table.
# Region Size in the original output is the total size of the region.

function to_bytes(value, unit)
{
    if (unit == "KB") return value * 1024;
    if (unit == "MB") return value * 1024 * 1024;
    if (unit == "GB") return value * 1024 * 1024 * 1024;
    return value;
}

function human_size(value)
{
    if (value == 0) return "0 B";
    if ((value % (1024 * 1024)) == 0) return sprintf("%d MB", value / (1024 * 1024));
    if ((value % 1024) == 0) return sprintf("%d KB", value / 1024);
    if (value >= (1024 * 1024)) return sprintf("%.2f MB", value / (1024 * 1024));
    if (value >= 1024) return sprintf("%.2f KB", value / 1024);
    return sprintf("%d B", value);
}

BEGIN {
    printf "%-36s %12s %12s %12s %11s\n", \
           "Memory region", "Total Size", "Used Size", "Free Size", "%age Used";
}

/^[[:space:]]*[^[:space:]]+:/ {
    region = $1;
    sub(/:$/, "", region);

    used_bytes = to_bytes($2, $3);
    total_bytes = to_bytes($4, $5);
    free_bytes = total_bytes - used_bytes;
    if (free_bytes < 0) free_bytes = 0;

    if (total_bytes == 0)
        usage = "N/A";
    else
        usage = sprintf("%.2f%%", (used_bytes * 100.0) / total_bytes);

    printf "%-36s %12s %12s %12s %11s\n", \
           region, human_size(total_bytes), human_size(used_bytes), \
           human_size(free_bytes), usage;
}
