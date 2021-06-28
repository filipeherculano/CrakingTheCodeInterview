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
    _n = read() |> String.to_integer()
    array = read() |> String.split(" ")

    jump(array, 0) |> write()
  end

  defp jump(["0" | [_ | ["0" | _] = rest]], it), do: jump(rest, it + 1)
  defp jump(["0" | ["0" | _] = rest], it), do: jump(rest, it + 1)
  defp jump(["0" | []], it), do: it
end

Solution.solve()
