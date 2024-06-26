import gleam/list
import gleam/result
import gleam/string
import simplifile

pub fn read_emails(path: String) -> Result(List(String), Nil) {
  path
  |> simplifile.read
  |> result.nil_error
  |> result.unwrap("")
  |> string.trim
  |> string.split("\n")
  |> Ok
}

pub fn create_log_file(path: String) -> Result(Nil, Nil) {
  simplifile.create_file(path)
  |> result.nil_error
}

pub fn log_sent_email(path: String, email: String) -> Result(Nil, Nil) {
  simplifile.append(path, email <> "\n")
  |> result.nil_error
}

pub fn send_newsletter(
  emails_path: String,
  log_path: String,
  send_email: fn(String) -> Result(Nil, Nil),
) -> Result(Nil, Nil) {
  let _ = create_log_file(log_path)
  emails_path
  |> read_emails
  |> result.unwrap([])
  |> list.try_each(fn(email) {
    case send_email(email) {
      Ok(_) -> log_sent_email(log_path, email)
      _ -> Ok(Nil)
    }
  })
  |> result.nil_error
}
