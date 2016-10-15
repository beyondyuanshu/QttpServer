#include "action.h"

using namespace std;
using namespace qttp;

const QList<Input> Action::m_EmptyInputList;
const QStringList Action::m_EmptyStringList;
const QList<std::pair<string, string> > Action::m_EmptyStringPairList;

Action::Action()
{
}

Action::~Action()
{
}

void Action::onAction(HttpData &data)
{
  HttpMethod method = Utils::fromPartialString(data.getRequest().get_method());
  switch(method)
  {
    case HttpMethod::GET:
      this->onGet(data);
      break;

    case HttpMethod::POST:
      this->onPost(data);
      break;

    case HttpMethod::PUT:
      this->onPut(data);
      break;

    case HttpMethod::DELETE:
      this->onDelete(data);
      break;

    case HttpMethod::PATCH:
      this->onPatch(data);
      break;

    case HttpMethod::HEAD:
      this->onHead(data);
      break;

    case HttpMethod::OPTIONS:
      this->onOptions(data);
      break;

    case HttpMethod::TRACE:
      this->onTrace(data);
      break;

    case HttpMethod::CONNECT:
      this->onConnect(data);
      break;

    default:
      this->onUnknown(data);
      break;
  }
}

void Action::onGet(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onPost(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onPut(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onPatch(HttpData &data)
{
  Q_UNUSED(data);
}

void Action::onHead(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onDelete(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onOptions(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onTrace(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onConnect(HttpData& data)
{
  Q_UNUSED(data);
}

void Action::onUnknown(HttpData& data)
{
  Q_UNUSED(data);
}

const QList<pair<HttpMethod, QString> >& Action::getRoutes() const
{
  const static QList<pair<HttpMethod, QString> > list;
  return list;
}

const char* Action::getSummary() const
{
  return "";
}

const char* Action::getDescription() const
{
  return "";
}

const QStringList& Action::getTags() const
{
  return m_EmptyStringList;
}

const QList<Input>& Action::getInputs() const
{
  return m_EmptyInputList;
}

const QList<pair<string, string> >& Action::getHeaders() const
{
  static const QList<pair<string, string> > defaultHeaders =
  {
    { "Content-Type", "application/json" },
    { "Access-Control-Allow-Headers", "Content-Type, Authorization" },
    { "Access-Control-Allow-Methods", "GET, POST, DELETE, PUT, PATCH, HEAD, OPTIONS, TRACE" },
    { "Access-Control-Allow-Origin", "*" },
    { "Server", QTTP_SERVER_VERSION }
  };
  return defaultHeaders;
}

void Action::applyHeaders(HttpData& data) const
{
  auto & resp = data.getResponse();
  for(auto & header : getHeaders())
  {
    resp.set_header(header.first, header.second);
  }
}

Input::Input() :
  name(),
  description(),
  required(false),
  paramType("query"),
  dataType("string"),
  enums()
{
}

Input::Input(const QString& n) :
  name(n),
  description(),
  required(false),
  paramType("query"),
  dataType("string"),
  enums()
{
}

Input::Input(const QString& n, const QStringList& e) :
  name(n),
  description(),
  required(false),
  paramType("query"),
  dataType("string"),
  enums(e)
{
}

RequiredInput::RequiredInput() :
  Input()
{
}

RequiredInput::RequiredInput(const QString& n) :
  Input(n)
{
  required = true;
}

RequiredInput::RequiredInput(const QString& n, const QStringList& e) :
  Input(n, e)
{
  required = true;
}

Processor::Processor()
{
}

Processor::~Processor()
{
}

void Processor::preprocess(HttpData& data)
{
  Q_UNUSED(data);
}

void Processor::postprocess(HttpData& data)
{
  Q_UNUSED(data);
}
