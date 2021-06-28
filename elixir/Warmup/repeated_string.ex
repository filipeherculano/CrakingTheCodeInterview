defmodule Solution do
  def read do
    case IO.read(:stdio, :line) do
      :eof ->
        :ok

      {:error, reason} ->
        IO.puts("Error: #{reason}")

      data ->
        String.replace_trailing(data, "\n", "")
    end
  end

  def write(answer) do
    answer = answer |> Integer.to_string() |> to_charlist()
    :ok = IO.write(answer)
  end

  def solve() do
    s = read()
    n = read() |> String.to_integer()

    div = Integer.floor_div(n, String.length(s))
    mod = Integer.mod(n, String.length(s))
    snippet = String.slice(s, 0, mod)
    a = s |> to_charlist |> Enum.reject(&(&1 != ?a)) |> Enum.count() |> Kernel.*(div)
    b = snippet |> to_charlist |> Enum.reject(&(&1 != ?a)) |> Enum.count()

    write(a + b)
  end
end

Solution.solve()
