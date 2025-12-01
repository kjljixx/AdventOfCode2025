const std = @import("std");

pub fn main() !void {
  var line_buffer: [1024]u8 = undefined;
  var w: std.io.Writer = .fixed(&line_buffer);
  var stdin_buffer: [1024]u8 = undefined;
  var writer = std.fs.File.stdin().reader(&stdin_buffer);

  var input = std.ArrayList([]u8).empty;
    const line_length = try writer.interface.streamDelimiterLimit(&w, '\n', .unlimited);
    try input.append(std.heap.page_allocator, line_buffer[0..line_length]);
    try std.fs.File.stdout().writeAll("hi");
  // const line_length = try writer.interface.streamDelimiterLimit(&w, '\n', .unlimited);
  // const input_line = line_buffer[0..line_length];
  // try std.fs.File.stdout().writeAll(input.items[0]);
}